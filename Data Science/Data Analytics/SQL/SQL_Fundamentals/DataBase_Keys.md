<div class="track_body__GeGQu">
  <h3><span>Introduction</span></h3>
  <p dir="ltr">
    <span
      >Understanding database keys is foundational to grasping how relational
      databases work. Database keys help to identify records uniquely, establish
      relationships between tables, ensure data integrity, and facilitate data
      manipulation. They serve as the cornerstone for complex operations like
      joins, updates, and deletes. In this article, we will delve deep into the
      types of database keys, their properties, uses, and practical
      examples.</span
    >
  </p>
  <h3><span>Types of Database Keys</span></h3>
  <p dir="ltr">
    <b><strong>1. Primary Key</strong></b>
  </p>
  <p dir="ltr">
    <span
      >The primary key uniquely identifies each record in a table. It cannot
      contain NULL values, and each table can have only one primary key. The
      primary key is usually set during table creation and can be composed of
      one or multiple columns.</span
    >
  </p>
  <p dir="ltr">
    <b><strong>Example</strong></b>
  </p>
  <p dir="ltr">
    <i><em class="GFGEditorTheme__textItalic">CREATE TABLE Students (</em></i>
  </p>
  <p dir="ltr">
    <i
      ><em class="GFGEditorTheme__textItalic">
        StudentID INT PRIMARY KEY,</em
      ></i
    >
  </p>
  <p dir="ltr">
    <i><em class="GFGEditorTheme__textItalic"> FirstName VARCHAR(50),</em></i>
  </p>
  <p dir="ltr">
    <i><em class="GFGEditorTheme__textItalic"> LastName VARCHAR(50)</em></i>
  </p>
  <p>
    <i><em class="GFGEditorTheme__textItalic">);</em></i>
  </p>
  <p dir="ltr">
    <b><strong>2. Foreign Key</strong></b>
  </p>
  <p dir="ltr">
    <span
      >A foreign key is a column or a set of columns that is used to establish a
      relationship between the data in two tables. It is related to the primary
      key in another table and ensures referential integrity.</span
    >
  </p>
  <p>
    <b><strong>Example</strong></b>
  </p>
  <p dir="ltr">
    <i
      ><em class="GFGEditorTheme__textItalic">CREATE TABLE Enrollments (</em></i
    >
  </p>
  <p dir="ltr">
    <i
      ><em class="GFGEditorTheme__textItalic">
        EnrollmentID INT PRIMARY KEY,</em
      ></i
    >
  </p>
  <p dir="ltr">
    <i><em class="GFGEditorTheme__textItalic"> StudentID INT,</em></i>
  </p>
  <p dir="ltr">
    <i><em class="GFGEditorTheme__textItalic"> CourseID INT,</em></i>
  </p>
  <p dir="ltr">
    <i
      ><em class="GFGEditorTheme__textItalic">
        FOREIGN KEY (StudentID) REFERENCES Students(StudentID)</em
      ></i
    >
  </p>
  <p>
    <i><em class="GFGEditorTheme__textItalic">);</em></i>
  </p>
  <p dir="ltr">
    <b><strong>3. Unique Key</strong></b>
  </p>
  <p dir="ltr">
    <span
      >A unique key is a key that ensures all the values in a column are
      different. Unlike the primary key, a table can have multiple unique keys,
      and the unique key column can have NULL values.</span
    >
  </p>
  <p>
    <b><strong>Example</strong></b>
  </p>
  <p dir="ltr">
    <i
      ><em class="GFGEditorTheme__textItalic">CREATE TABLE Departments (</em></i
    >
  </p>
  <p dir="ltr">
    <i
      ><em class="GFGEditorTheme__textItalic">
        DepartmentID INT PRIMARY KEY,</em
      ></i
    >
  </p>
  <p dir="ltr">
    <i
      ><em class="GFGEditorTheme__textItalic"> DepartmentCode INT UNIQUE</em></i
    >
  </p>
  <p>
    <i><em class="GFGEditorTheme__textItalic">);</em></i>
  </p>
  <p dir="ltr">
    <b><strong>4. Composite Key</strong></b>
  </p>
  <p dir="ltr">
    <span
      >A composite key is a key that consists of more than one column to
      uniquely identify each record. It is used when a single column is not
      sufficient to uniquely identify records.</span
    ><br /><br /><b><strong>Example</strong></b>
  </p>
  <p dir="ltr">
    <i
      ><em class="GFGEditorTheme__textItalic"
        >CREATE TABLE OrderDetails (</em
      ></i
    >
  </p>
  <p dir="ltr">
    <i><em class="GFGEditorTheme__textItalic"> OrderID INT,</em></i>
  </p>
  <p dir="ltr">
    <i><em class="GFGEditorTheme__textItalic"> ProductID INT,</em></i>
  </p>
  <p dir="ltr">
    <i
      ><em class="GFGEditorTheme__textItalic">
        PRIMARY KEY (OrderID, ProductID)</em
      ></i
    >
  </p>
  <p>
    <i><em class="GFGEditorTheme__textItalic">);</em></i>
  </p>
  <p dir="ltr">
    <b><strong>5. Candidate Key</strong></b>
  </p>
  <p dir="ltr">
    <span
      >A candidate key is a key that can uniquely identify records in a table. A
      table may have multiple candidate keys, but one of these is chosen as the
      primary key. Candidate keys are essentially unique keys that can be
      primary if chosen.</span
    >
  </p>
  <p>
    <b><strong>Example</strong></b>
  </p>
  <p dir="ltr">
    <i><em class="GFGEditorTheme__textItalic">CREATE TABLE Books (</em></i>
  </p>
  <p dir="ltr">
    <i><em class="GFGEditorTheme__textItalic"> ISBN INT PRIMARY KEY,</em></i>
  </p>
  <p dir="ltr">
    <i><em class="GFGEditorTheme__textItalic"> BookCode INT UNIQUE</em></i>
  </p>
  <p>
    <i><em class="GFGEditorTheme__textItalic">);</em></i>
  </p>
  <p dir="ltr">
    <b><strong>6. Super Key</strong></b>
  </p>
  <p dir="ltr">
    <span
      >A super key is a set of one or more columns that can be used to uniquely
      identify records within a table. The difference between a super key and a
      candidate key is that a super key can have additional columns that are not
      strictly necessary for unique identification.</span
    >
  </p>
  <p>
    <b><strong>Example</strong></b>
  </p>
  <p dir="ltr">
    <span
      >In the Students table, a super key could be (StudentID, FirstName).</span
    >
  </p>
  <p dir="ltr">
    <b><strong>7. Alternate Key</strong></b>
  </p>
  <p dir="ltr">
    <span
      >Alternate keys are keys that are not selected as the primary key but
      could be if needed. They are essentially candidate keys that are not
      chosen as the primary key.</span
    ><br /><br /><b><strong>Example</strong></b>
  </p>
  <p dir="ltr">
    <span>In the Books table, BookCode could be an alternate key.</span>
  </p>
  <p dir="ltr">
    <b><strong>8. Natural Key and Surrogate Key</strong></b>
  </p>
  <p dir="ltr">
    <b><strong>Natural Key</strong></b
    ><span
      >: A key that has a logical relationship to the attributes within that
      row.</span
    >
  </p>
  <p dir="ltr">
    <b><strong>Surrogate Key:</strong></b
    ><span>
      A key that has no logical meaning and is usually auto-generated by the
      system.</span
    >
  </p>
  <p dir="ltr">
    <b><strong>Example</strong></b>
  </p>
  <p dir="ltr">
    <span
      >In the Employees table, an EmployeeID could be a surrogate key, whereas
      an Employee Social Security Number could be a natural key.</span
    >
  </p>
  <h3><span>Practical Uses of Database Keys</span></h3>
  <p dir="ltr">
    <b><strong>Data Integrity</strong></b
    ><span
      >: Keys enforce data integrity by ensuring that the data within the
      database is accurate and consistent.</span
    >
  </p>
  <p dir="ltr">
    <b><strong>Efficiency:</strong></b
    ><span>
      They improve query performance by enabling better indexing
      strategies.</span
    >
  </p>
  <p dir="ltr">
    <b><strong>Relationships</strong></b
    ><span
      >: Keys define the relationships between tables, making it easier to join
      tables and perform complex queries.</span
    >
  </p>
  <h3><span>Summary</span></h3>
  <p dir="ltr">
    <span
      >Understanding database keys is vital for anyone dealing with databases.
      They serve to enforce integrity, improve query performance, and define
      relationships. A thorough grasp of database keys is crucial for effective
      data manipulation and integrity in relational databases.</span
    >
  </p>
</div>
