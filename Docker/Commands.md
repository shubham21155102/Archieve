```shell
#image creation
docker run -p 3307:3306 --name mysqldb -e MYSQL_ROOT_PASSWORD=123456 -d mysql:8.2.0
docker mysql:8.2.0 tag shubham21155102/mysql:8.2.0   
docker push shubham21155102/mysql:8.2.0  
```
