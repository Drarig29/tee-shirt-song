# Tee-shirt song

[![Release](https://github.com/Drarig29/tee-shirt-song/actions/workflows/release.yml/badge.svg)](https://github.com/Drarig29/tee-shirt-song/actions/workflows/release.yml)

You will also find a [C++ program](src/main.cpp) which runs the song! 😎

The code below is actually implemented and programmatically outputs the lyrics, this is not hardcoded. The logic sits in a [separated file](src/logic.hpp).

If VLC is installed on your computer, the MIDI file embedded in the code will be played.
**Note:**  On Linux, VLC requires the `vlc-plugin-fluidsynth` plugin to play MIDI files ([more info](https://wiki.videolan.org/Midi/)).

![Demo of the executable](demo.gif)

## Run it

To run the program without compiling it, run the following:

```bash
bash <(curl -s https://drarig29.github.io/tee-shirt-song/run.sh)
```

## Disclaimer

I made this translation from a song's lyrics into source code with JavaScript in mind. But to actually implement it, I had to use a lower level language to overload operators, so I chose C++.

Because I used C++, the only difference you'll see between the original source code and the C++ implementation will be the strings (with the use double quotes instead of single quotes) and the lambda function syntax.

## Copyright

You can make your own tee-shirt with this "art", I own one personally. If you need the SVG file, just ask me.
