#!/bin/bash
if ! [ -d ~/utblib ]; then mkdir ~/utblib; fi
g++ -fPIC -std=c++17 utbDir.cpp utilities.cpp -shared -o ~/utblib/libutbDir.so
g++ -fPIC -std=c++17 utbFile.cpp utilities.cpp -shared -o ~/utblib/libutbFile.so
g++ -fPIC -std=c++17 utbText.cpp utilities.cpp -shared -o ~/utblib/libutbText.so
g++ -fPIC -std=c++17 utbShell.cpp utilities.cpp -shared -o ~/utblib/libutbShell.so
g++ -fPIC -std=c++17 -Wno-attributes utbBegin.cpp pt4utilities.cpp -shared -o ~/utblib/libutbBegin.so
g++ -fPIC -std=c++17 -Wno-attributes utbInteger.cpp pt4utilities.cpp -shared -o ~/utblib/libutbInteger.so
g++ -fPIC -std=c++17 -Wno-attributes utbBoolean.cpp pt4utilities.cpp -shared -o ~/utblib/libutbBoolean.so
g++ -fPIC -std=c++17 -Wno-attributes utbIf.cpp pt4utilities.cpp -shared -o ~/utblib/libutbIf.so
g++ -fPIC -std=c++17 -Wno-attributes utbCase.cpp pt4utilities.cpp -shared -o ~/utblib/libutbCase.so
g++ -fPIC -std=c++17 -Wno-attributes utbFor.cpp pt4utilities.cpp -shared -o ~/utblib/libutbFor.so
g++ -fPIC -std=c++17 -Wno-attributes utbWhile.cpp pt4utilities.cpp -shared -o ~/utblib/libutbWhile.so
g++ -fPIC -std=c++17 -Wno-attributes utbProc.cpp pt4utilities.cpp -shared -o ~/utblib/libutbProc.so
g++ -fPIC -std=c++17 -Wno-attributes utbZSeries.cpp pt4utilities.cpp -shared -o ~/utblib/libutbZSeries.so
g++ -fPIC -std=c++17 -Wno-attributes utbZMinmax.cpp pt4utilities.cpp -shared -o ~/utblib/libutbZMinmax.so
g++ -fPIC -std=c++17 -Wno-attributes utbZArray.cpp pt4utilities.cpp -shared -o ~/utblib/libutbZArray.so
g++ -fPIC -std=c++17 -Wno-attributes utbZMatrix.cpp pt4utilities.cpp -shared -o ~/utblib/libutbZMatrix.so
g++ -fPIC -std=c++17 -Wno-attributes utbString.cpp pt4utilities.cpp -shared -o ~/utblib/libutbString.so