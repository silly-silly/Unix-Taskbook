#include "utilities.hpp"

namespace utilities
{
	bool exists_file(std::string filename)
	{
		int f = open(filename.c_str(), O_RDONLY);
		if (f == -1)
		{
			return false;
		}
		close(f);
		return true;
	}
	void show_file(const char *name, const char *comment, int filetype)
	// filetype == 0 for binary and .gcclog files,
	//             1 for _control.tst file,
	//             2 for other .tst files
	{
		int flines = 1000;
		char cmd[200];
		if (filetype != 1)
		{
			//std::cout << CYAN << "===" << comment << name << "===" << BROWN << std::endl;
			std::cout << CYAN << format_info("[ " + std::string(comment) + std::string(name) + " ]", ' ', false) << RESET << std::endl;
		}
		else
		{
			//std::cout << CYAN << "===" << comment << BROWN << std::endl;
			std::cout << CYAN << format_info("[ " + std::string(comment) + " ]", ' ', false) << RESET << std::endl;
		}
		if (filetype == 0 || flines >= 1000)
		{
			sprintf(cmd, "cat %s", name);
			system(cmd);
			//LOG_FILE("\n===End Of File===");
			LOG_FILE("\n%s", format_info("[ end of file ]", ' ', false).c_str());
		}
		else
		{
			int f = open(name, O_RDONLY);
			int n;
			int cnt = 0;
			while ((n = read_line(f, cmd, 200)) > 0)
			{
				cnt++;
				if (cnt <= flines)
				{
					std::cout << cmd;
				}
				else
				{
					break;
				}
			}
			close(f);
			if (cnt <= flines)
			{
				LOG_FILE("===End of file===");
			}
			else
			{
				LOG_FILE("===%d initial lines of file are shown===", flines);
			}
		}
	}
	void show_file(std::string name, const char *comment, int filetype)
	{
		show_file(name.c_str(), comment, filetype);
	}
	ssize_t read_line(int fd, void *sbuf, size_t sbufsize)
	{
		ssize_t n, rc;
		char c, *ptr;
		ptr = (char *)sbuf;
		for (n = 1; n < sbufsize; n++)
		{
			if ((rc = read(fd, &c, 1)) == 1)
			{
				if (c == '\r')
				{
					n--;
					continue;
				}
				*ptr++ = c;
				if (c == '\n')
				{
					*ptr = 0;
					return n;
				}
			}
			else if (rc == 0)
			{
				*ptr = 0;
				return n - 1;
			}
			else
			{
				return -1;
			}
		}
		*ptr = 0;
		return n - 1;
	}
	int compare_file(const char *name1, const char *name2)
	{
		int f1 = open(name1, O_RDONLY);
		int f2 = open(name2, O_RDONLY);
		char buf1[MAX_SIZE];
		char buf2[MAX_SIZE];
		int n1 = read(f1, buf1, sizeof(buf1));
		int n2 = read(f2, buf2, sizeof(buf2));
		close(f1);
		close(f2);
		if (n1 != n2)
		{
			return 1;
		}

		for (int i = 0; i < n1; i++)
		{
			if (buf1[i] != buf2[i])
			{
				return 2;
			}
		}

		return 0;
	}
	int compare_file(std::string name1, std::string name2)
	{
		return compare_file(name1.c_str(), name2.c_str());
	}
	std::string generate_random_name(size_t length)
	{
		std::string name;
		char buf[length + 1];
		for (size_t i = 0; i < length; i++)
		{
			buf[i] = 'a' + (rand() % 26);
		}
		buf[length] = 0;
		name = buf;
		return name;
	}
	void init_random_test_files_name(std::vector<std::string> &test_files, size_t test_file_count)
	{
		test_files.resize(test_file_count);

		for (auto &tf : test_files)
		{
			tf = generate_random_name(8) + ".tst";
		}
	}
	void get_files_in_dir(std::string dir, std::vector<std::string> &files)
	{
		DIR *dp;
		struct dirent *dirp;
		if ((dp = opendir(dir.c_str())) == NULL)
		{
			return;
		}
		while ((dirp = readdir(dp)) != NULL)
		{
			std::string name = dirp->d_name;
			if (name != "." && name != "..")
			{
				files.push_back(name);
			}
		}
		closedir(dp);
	}
	//根据utf8字符的首字节,获取utf8字符所占字节数
	uint8_t GetUtf8charByteNum(unsigned char ch)
	{
		uint8_t byteNum = 0;
		if (ch >= 0xFC && ch < 0xFE)
			byteNum = 6;
		else if (ch >= 0xF8)
			byteNum = 5;
		else if (ch >= 0xF0)
			byteNum = 4;
		else if (ch >= 0xE0)
			byteNum = 3;
		else if (ch >= 0xC0)
			byteNum = 2;
		else
			byteNum = 1;
		return byteNum;
	}
	size_t get_next_word_size(std::string str, size_t start, size_t length)
	{
		const char *chs = str.c_str();
		size_t i = start;
		while (chs[i] != ' ' && chs[i] != '\t' && chs[i] != '\n' && i < strlen(chs) && (i - start) < length)
		{
			i += GetUtf8charByteNum(chs[i]);
		}
		// std::cout << str.substr(start, i - start) << std::endl;
		return i - start;
	}
	size_t normalized_output(std::string s, size_t start, size_t length)
	{
		const char *chs = s.c_str();

		while (chs[start] == '\n' || chs[start] == ' ')
		{
			start++;
		}
		size_t end = start;
		while (end < strlen(chs) && (end - start) < length)
		{
			end += get_next_word_size(s, end, length);
			if (end < strlen(chs) && (end - start) < length && chs[end] == '\n')
			{
				end++;
				break;
			}
			if ((end + 1 - start) < length)
			{
				end++;
			}
			else
			{
				break;
			}
		}
		if (end > s.length())
		{
			end = s.length();
		}

		std::cout << std::setw(end - start) << s.substr(start, end - start) << std::endl;
		return end;
	}
	void normalized_output_text(std::string text, size_t row_size)
	{
		size_t text_size = text.size();
		size_t end = normalized_output(text, 0, row_size);
		while (end < text_size)
		{
			end = normalized_output(text, end, row_size);
		}
	}

	std::string format_info(const std::string &info, const char marker, bool margin)
	{
		const int max_len = 81;
		int num = (max_len - info.size()) / 2;
		std::string ret;
		if (margin)
			ret = '[' + std::string(num + 1, marker) + info + std::string(num, marker) + ']';
		else
			ret = std::string(num + 1, marker) + info + std::string(num + 1, marker);
		return ret;
	}
}