# Data Reading from a File

We can read any data from a file just using follwing

```python
- a=open('data.txt' , 'r')
- txt = a.read()
- print(txt)
- a.close()
```

Data in the 'data.txt' file will be displayed .

### Reading the file

- .read()
- .readline()
- .readlines()

  ```python
  File_object = open(r"File_Name","r")
  File_object.read([n])
  File_object.readline([n])
   File_object.readlines()
  ```

## Data from Large file

```python
- a=open('data.txt' , 'r')
- txt = a.read()
- txt = txt.remove('\n\n' , ' ')
- print(txt)
- a.close()
```

Here the the line change is marked with '/n' special character . All these are ignored if we just run the txt statement but ifwe print the txt then all the indentations are same as in the text file.

## Text Preprocessing

Text Preprocessing means doing analysis of the text data such as separating into paragraphs , lines , words and finding most easy and suitable format for doing analysis

### Paragraphs

```python
- txt = txt.split('\n\n') # Paragraphs are seaprated with lines
```

### Lines

```python
- txt = txt.split('.') # Lines are seaparated with full stops
```

### Words

```python
- txt = txt.split(' ') #words are separated with space
```

These .split() function returns a list [] . so we can apply all the list algos to do analysis.

### Data Cleaning also becomes a part of Text Preprocessing

for example:

lets suppose we have to remove all the numbers in string format from the data starting from [1] to [19]

```python
for i in range(1,20):
	pattern = "[" + str(i) + "]"
	txt.replace(pattern , "") # replacing the string with empty string

```

# Writing and updating the data in a file

- We use mode as 'w' for writing and 'a' for appending the data for appending .

  - Appending continues with the already present data and adds your new data there but writing starts from fresh and gives your new data there in the file.

  ```python
  fd = open("data.txt" , 'w')
  fd.write("My Name is Satyam and I m a student at IIT BHU Varanasi")
  fd.close()

  fd1 = open("data.txt" , 'a')
  fd1.write("My Name is Satyam and I m a student at IIT BHU Varanasi")
  fd1.close()
  ```
- we can add '\n' to change the line while writing in the write or append mode

  ### .write() and .writelines()


  ```python
  File_object = open(r"File_Name","Access_Mode")
  File_object.write(str1)
  File_object.writelines(L) for L = [str1, str2, str3] 
  ```
