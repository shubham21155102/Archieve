
# Numpy

- It is a multipurpose array processing language.
- It is a fundamental package for scientific computation in python.
- It can be installed in your system as pip install numpy.


### Basic Initialisation of Numpy:

- import numpy as np --> # This is importing numpy library into your working envirnment.
- arr = np.array([1,2,3,4,5,6,7,8,9])
- print(arr)--->[1,2,3,4,5,6,7,8,9]

## Some Important functions in  Numpy :

- ### np.shape
- ### np.ndim
- ### np.dtype
- ### np.random.random()
- ### np.random.randint()
- ### np.arange()
- ### np.linspace()
- ### np.reshape()
- ### np.sort()
- ### np.vstack()
- ### np.hstack()
- ### np.hsplit()
- ### np.vsplit()
- ### np.concatenate()


# Note:

- np.flipud(arr) is used to reverse the numpy array.
- np.column_stack((arr1,arr2)) --> This stacks the two nd array into 2D array
- np.full(shape , value)

# Some Codes are given below for better Understanding :

```python
import numpy as np
 
# Defining both the matrices
a = np.array([5, 72, 13, 100])
b = np.array([2, 5, 10, 30])
 
# Performing addition using arithmetic operator
add_ans = a+b
print(add_ans)
 
# Performing addition using numpy function
add_ans = np.add(a, b)
print(add_ans)
 
# The same functions and operations can be used for multiple matrices
c = np.array([1, 2, 3, 4])
add_ans = a+b+c
print(add_ans)
 
add_ans = np.add(a, b, c)
print(add_ans)
```


```python
# import numpy library
import numpy
 
# creating a two dimensional
# numpy array of integers
arr = numpy.array([[11, 2, 3],
                     [4, 5, 16],
                      [7, 81, 22]])
 
# finding the maximum and
# minimum element in the array
max_element_column = numpy.max(arr, 0)
max_element_row = numpy.max(arr, 1)
 
min_element_column = numpy.amin(arr, 0)
min_element_row = numpy.amin(arr, 1)
 
# printing the result
print('maximum elements in the columns of the array is:',
      max_element_column)
 
print('maximum elements in the rows of the array is:',
      max_element_row)
 
print('minimum elements in the columns of the array is:',
      min_element_column)
 
print('minimum elements in the rows of the array is:',
      min_element_row)


arr = np.array([[7,3,8,6,4], [7,2,9,8,6],[5,4,2,3,1]])
print(np.sort(arr , axis = 0, kind = 'mergesort'))
print()
print(np.sort(arr , axis = 1, kind = 'quicksort'))
print()
print(np.sort(arr , kind = 'heapsort'))
```
