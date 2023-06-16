# Tee-shirt song

[![Release](https://github.com/Drarig29/tee-shirt-song/actions/workflows/release.yml/badge.svg)](https://github.com/Drarig29/tee-shirt-song/actions/workflows/release.yml)

The code below ([source](https://github.com/Drarig29/tee-shirt-song/blob/main/src/main.cpp)) **DOES** work and it outputs the lyrics (as shown in the gif below).

Nothing is hardcoded.

```cpp
#include "logic.hpp"

int main()
{
  /**
   * Guess the song... 😌 😎
   */

  imagine(!heaven) == "easy";
  us.below = !hell;
  us.above = sky;
  imagineAll("living for today");

  imagine(!countries) != "hard";
  (kill || die).reasons.length == 0;
  religion = undefined;
  imagineAll("living life in peace");

  chorus(); //🎵🎶

  imagine(!possessions) ? "😀" : "😥";
  need(greed || hunger) == false;
  men.reduce([]() { return "brothers"; });
  imagineAll("sharing all the world");

  chorus(); //🎵🎶
}
```

![Demo of the executable](demo.gif)

## Run it

To run the program without compiling it, run the following:

```bash
bash <(curl -s https://drarig29.github.io/tee-shirt-song/run.sh)
```

If VLC is installed on your computer, the MIDI file embedded in the code will be played.

**Note:**  On Linux, VLC requires the `vlc-plugin-fluidsynth` plugin to play MIDI files ([more info](https://wiki.videolan.org/Midi/)).

## Disclaimer

I made this translation from a song's lyrics into source code with JavaScript in mind. But to actually implement it, I had to use a lower level language to overload operators, so I chose C++.

Because I used C++, the only difference you'll see between the original source code and the C++ implementation will be the strings (with the use double quotes instead of single quotes) and the lambda function syntax.

## Copyright

You can make your own tee-shirt with this "art", I own one personally. If you need the SVG file, just ask me.
