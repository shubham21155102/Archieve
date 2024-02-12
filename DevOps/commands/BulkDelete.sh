## Commnad to delete all the images
docker rmi -f $(docker images -a -q)
## Command to delete all the containers
docker image prune -f
