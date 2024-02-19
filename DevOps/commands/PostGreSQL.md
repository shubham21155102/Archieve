- Connect to PostGreSQL

```
psql -h username -p 5432 -U postgres
```

- List all databases

```
\l
```

- List all databases

```
SELECT datname FROM pg_database;
```

- Connect to a specific database

```
psql -d dev
```

- Connect to a specific database if you are already connected to PostGreSQL's default database

```
\c dev
```

- List all tables in a database

```
\dt
```
