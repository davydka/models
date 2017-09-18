`ffmpeg -y -i bin/data/sequence/%04d.png -c:v libx264 -vf "fps=30,format=yuv420p" video.mp4`
