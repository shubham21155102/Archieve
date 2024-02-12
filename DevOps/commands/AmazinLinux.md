# Amazon Linux

## Installation of Amazon linux in Docker

- First Downloading images

  ```shell
  docker pull amazonlinux
  ```

- Docker to provide a JSON representation of all the metadata associated with the `amazonlinux` image.

  ```shell
  docker image inspect amazonlinux
  ```

- export the filesystem of a Docker container created from the `amazonlinux` image to a TAR archive named `amazonlinux.tar`.

  ```shell
  docker export $(docker create amazonlinux) > amazonlinux.tar
  ```

- Interacting with Amazon linux

  ```shell
  docker run -it amazonlinux /bin/bash
  ```

## Amazon Linux Commands

- Clear Command
  ```shell
  printf "\033c"
  ```
