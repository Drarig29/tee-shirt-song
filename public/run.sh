# Delete previous downloads
rm tee_shirt_song*

# Download current release's artifact
wget --quiet https://github.com/Drarig29/tee-shirt-song/releases/download/v1.0/tee_shirt_song

# Run the program
chmod +x tee_shirt_song
./tee_shirt_song