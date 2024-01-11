FROM ubuntu:latest As build
RUN apt-get update && apt-get install -y build-essential
copy . .
RUN gcc -2.c -o 2 -pthread
