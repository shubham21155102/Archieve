# Docker Commands

### Image Builder

```shell
docker build -t <image-name> .
```

### Run Container

```shell
docker run -d -p 8080:8080 <image-name>
```

```shell
docker tag build-server:latest shubham21155102/vercel:build-server
```

- Pulling an Image

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
