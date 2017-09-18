`ffmpeg -y -i bin/data/sequence/%04d.png -c:v libx264 -vf "fps=30,format=yuv420p" -b 1600k video.mp4`
