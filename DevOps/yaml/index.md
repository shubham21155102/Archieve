```yaml
# Yet Another Markup Language
name: Shubham
age: 26
server:
  name: "Shubham Trial"
  capacity: 50TB
# List
social_media:
  - insta: shubhamiitbhu
  - website: shubhamiitbhu.in
  - linkedin: shubhamiitbhu
# multiline string
description: |
  shubham
  from 
  iit bhu
list_of_academics:
  - academics_1:
      year: 2013-2018
      classes: 6-10
  - academics_2:
      yaer: 2018-2020
      classes: 10-12
```

[]: #
[]: # YAML is a human-readable data serialization standard that can be used in conjunction with all programming languages and is often used to write configuration files. It is often used to write configuration files. It is a superset of JSON, another data serialization language, but is more human-readable than JSON. YAML is often used for configuration files, but it is also used in data storage and transmission. It is a popular choice for configuration files because it is easy to read and write, and it is easy for humans to understand. It is also easy for machines to parse and generate. YAML is often used in conjunction with other languages, such as Python, Ruby, and Perl. It is also used in conjunction with other data serialization languages, such as JSON and XML. YAML is often used in conjunction with other data serialization languages, such as JSON and XML. It is often used in conjunction with other data serialization languages, such as JSON and XML. YAML is often used in conjunction with other data serialization languages, such as JSON and XML. It is often used in conjunction with other data serialization languages, such as JSON and XML. YAML is often used in conjunction with other data serialization languages, such as JSON and XML. It is often used in conjunction with other data serialization languages, such as JSON and XML. YAML is often used in conjunction with other data serialization languages, such as JSON and XML. It is often used in conjunction with other data serialization languages, such as JSON and XML. YAML is often used in conjunction with other data serialization languages, such as JSON and XML. It is often used in conjunction with other data serialization languages, such as JSON and XML. YAML is often used in conjunction with other data serialization languages, such as JSON and XML. It is often used in conjunction with other data serialization languages, such as JSON and XML. YAML is often used in conjunction with other data serialization languages, such as JSON and XML. It is often used in conjunction with other data serialization languages, such as JSON and XML. YAML is often used in conjunction with other data serialization languages, such as JSON and XML. It is often used in conjunction with other data serialization languages, such as JSON and XML. YAML is often used in conjunction with other data serialization languages, such as JSON and XML.

```python
import yaml

with open("learn.yaml", 'r') as file:
    try:
        print(yaml.safe_load(file))
    except yaml.YAMLError as exc:
        print(exc)
with open("../docker-compose.yaml", 'r') as file:
    try:
        print(yaml.safe_load(file))
    except yaml.YAMLError as exc:
        print(exc)
```
