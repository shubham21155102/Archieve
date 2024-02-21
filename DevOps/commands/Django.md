- Install Django

```shell
  pip install django
```

- Check version on django

```shell
  python -m django --version
```

- Creating a project

```shell
django-admin startproject CreditApprovalSystem
```

- The development server

```shell
python3 manage.py runserver
```

- Changing the port

```shell
python3 manage.py runserver 8080
```

```shell
python3 manage.py runserver 0.0.0.0:8000
```

- Creating the System app

```shell
python3 manage.py startapp system
```

- Write our first view (system/views.py)

  ```python
  from django.http import HttpResponse


  def index(request):
      return HttpResponse("Hello, world. You're at the system index.")
  ```

- In the `system/urls.py` file include the following code:

  ```python
  from django.urls import path

  from . import views

  urlpatterns = [
    path("", views.index, name="index"),
   ]
  ```

- Add this to ProjectName/urls.py

  ```python
  from django.contrib import admin
  from django.urls import include, path

  urlpatterns = [
      path("system/", include("system.urls")),
      path("admin/", admin.site.urls),
  ]
  ```

- Some of these applications make use of at least one database table, though, so we need to create the tables in the database before we can use them. To do that, run the following command:

```shell
python3  manage.py migrate
```

- Now working with models folder of system directory

  ```python
  from django.db import models


  class Users(models.Model):
      userId = models.AutoField(primary_key=True)
      firstName = models.CharField(max_length=50)
      lastName = models.CharField(max_length=50)
      age = models.CharField(max_length=3)
      phoneNumber = models.CharField(max_length=10)
      monthlySalary = models.CharField(max_length=10)
      approvalLimit = models.CharField(max_length=10)
  ```

- In ProjectName/settings.py

  ```python
  INSTALLED_APPS = [
      "system.apps.SystemConfig",
      'django.contrib.admin',
      'django.contrib.auth',
      'django.contrib.contenttypes',
      'django.contrib.sessions',
      'django.contrib.messages',
      'django.contrib.staticfiles',
  ]
  ```

- Now Creating Our Models Using Command

```shell
python3 manage.py makemigrations system
```

```shell
python3 manage.py sqlmigrate system 0001
```

```powershell
BEGIN;
--
-- Create model Users
--
CREATE TABLE "system_users" ("userId" integer NOT NULL PRIMARY KEY AUTOINCREMENT, "firstName" varchar(50) NOT NULL, "lastName" varchar(50) NOT NULL, "phoneNumber" varchar(10) NOT NULL);
COMMIT;
```

- Deleting Existing table if got some error

  ```shell
  python3 manage.py dbshell

  sqlite> DROP TABLE system_users;

  sqlite> .exit
  ```

```shell
python3 manage.py createsuperuser
```
