<div class="track_article_contents__9JJFV">
  <p class="track_title__g20mM">Data (Intro, Data Types)</p>
  <hr />
  <div class="track_body__GeGQu">
    <h3><span>Introduction</span></h3>
    <p dir="ltr">
      <span
        >Data is the bedrock of any database management system, serving as the
        raw material that gets stored, manipulated, and retrieved. As data comes
        in various shapes and sizes, understanding the types of data and their
        classifications is crucial for anyone working with databases. This
        understanding can aid in effective database design, ensure data
        integrity, and optimize performance. In this comprehensive article,
        we'll explore the fundamental concept of data, its types, and examples
        to provide a well-rounded view.</span
      >
    </p>
    <h3><span>What is Data?</span></h3>
    <p dir="ltr">
      <span
        >In the context of databases, data refers to the individual pieces of
        information stored in a structured format within the database. Data
        could range from simple numerical values to complex textual content,
        timestamps, and more. It forms the essence of any application that
        relies on a database for data storage and retrieval.</span
      >
    </p>
    <h3><span>Classification of Data</span></h3>
    <p dir="ltr">
      <span
        >The classification of data within databases usually occurs at two
        levels:</span
      >
    </p>
    <p dir="ltr">
      <b><strong>Basic Types</strong></b
      ><span
        >: These are the primitive or atomic types provided by the DBMS.</span
      >
    </p>
    <p dir="ltr">
      <b><strong>Derived Types</strong></b
      ><span
        >: These are the types that are defined by the DBMS based on what is
        built into the system.</span
      >
    </p>
    <h3>
      <u><span class="GFGEditorTheme__textUnderline">Data Types</span></u>
    </h3>
    <h3>
      <b><strong>Numeric Data Types</strong></b>
    </h3>
    <p dir="ltr">
      <span
        >These data types are used to store numeric values. They can be divided
        into:</span
      >
    </p>
    <p dir="ltr"><span>Integer (INT)</span></p>
    <p dir="ltr"><span>Decimal (DECIMAL)</span></p>
    <p dir="ltr"><span>Float (FLOAT)</span></p>
    <p dir="ltr">
      <b><strong>Example</strong></b>
    </p>
    <p dir="ltr">
      <i><em class="GFGEditorTheme__textItalic">CREATE TABLE Finance (</em></i>
    </p>
    <p dir="ltr">
      <i><em class="GFGEditorTheme__textItalic"> Salary INT,</em></i>
    </p>
    <p dir="ltr">
      <i><em class="GFGEditorTheme__textItalic"> Bonus DECIMAL(5,2)</em></i>
    </p>
    <p>
      <i><em class="GFGEditorTheme__textItalic">);</em></i>
    </p>
    <h3>
      <b><strong>Textual Data Types</strong></b>
    </h3>
    <p dir="ltr">
      <span>Textual data types are used for storing text values:</span>
    </p>
    <p dir="ltr"><span>CHAR: Fixed-length character string.</span></p>
    <p dir="ltr"><span>VARCHAR: Variable-length character string.</span></p>
    <p dir="ltr"><span>TEXT: For large text documents.</span></p>
    <p dir="ltr">
      <b><strong>Example</strong></b>
    </p>
    <p dir="ltr">
      <i><em class="GFGEditorTheme__textItalic">CREATE TABLE Blogs (</em></i>
    </p>
    <p dir="ltr">
      <i><em class="GFGEditorTheme__textItalic"> Title VARCHAR(255),</em></i>
    </p>
    <p dir="ltr">
      <i><em class="GFGEditorTheme__textItalic"> Content TEXT</em></i>
    </p>
    <p>
      <i><em class="GFGEditorTheme__textItalic">);</em></i>
    </p>
    <h3><span>Date and Time Data Types</span></h3>
    <p dir="ltr">
      <span>These types are used to store time and date values:</span>
    </p>
    <p dir="ltr"><span>DATE: For date values.</span></p>
    <p dir="ltr"><span>TIME: For time values.</span></p>
    <p dir="ltr"><span>TIMESTAMP: For both date and time.</span></p>
    <p dir="ltr">
      <b><strong>Example</strong></b>
    </p>
    <p dir="ltr">
      <i><em class="GFGEditorTheme__textItalic">CREATE TABLE Events (</em></i>
    </p>
    <p dir="ltr">
      <i><em class="GFGEditorTheme__textItalic"> EventDate DATE,</em></i>
    </p>
    <p dir="ltr">
      <i><em class="GFGEditorTheme__textItalic"> EventTime TIME</em></i>
    </p>
    <p>
      <i><em class="GFGEditorTheme__textItalic">);</em></i>
    </p>
    <h3><span>Logical Data Types</span></h3>
    <p dir="ltr">
      <span>These are used to store boolean values like TRUE or FALSE:</span>
    </p>
    <p dir="ltr"><span>BOOLEAN</span></p>
    <p dir="ltr">
      <b><strong>Example</strong></b>
    </p>
    <p dir="ltr">
      <i><em class="GFGEditorTheme__textItalic">CREATE TABLE Members (</em></i>
    </p>
    <p dir="ltr">
      <i><em class="GFGEditorTheme__textItalic"> IsActive BOOLEAN</em></i>
    </p>
    <p>
      <i><em class="GFGEditorTheme__textItalic">);</em></i>
    </p>
    <h3><span>Binary Data Types</span></h3>
    <p dir="ltr">
      <span
        >These are used to store binary data like images, audio files,
        etc.:</span
      >
    </p>
    <p dir="ltr"><span>BINARY</span></p>
    <p dir="ltr"><span>VARBINARY</span></p>
    <p dir="ltr"><span>BLOB</span></p>
    <p dir="ltr">
      <b><strong>Example</strong></b>
    </p>
    <p dir="ltr">
      <i><em class="GFGEditorTheme__textItalic">CREATE TABLE Files (</em></i>
    </p>
    <p dir="ltr">
      <i><em class="GFGEditorTheme__textItalic"> Image BLOB</em></i>
    </p>
    <p>
      <i><em class="GFGEditorTheme__textItalic">);</em></i>
    </p>
    <h3><span>Complex Data Types</span></h3>
    <p dir="ltr">
      <span>Some databases also support more complex data types:</span>
    </p>
    <p dir="ltr"><span>ENUM: A static set of values.</span></p>
    <p dir="ltr"><span>ARRAY: An ordered collection of elements.</span></p>
    <p dir="ltr"><span>JSON: Stores JSON-formatted data.</span></p>
    <p dir="ltr">
      <b><strong>Example</strong></b>
    </p>
    <p dir="ltr">
      <i
        ><em class="GFGEditorTheme__textItalic"
          >CREATE TABLE Preferences (</em
        ></i
      >
    </p>
    <p dir="ltr">
      <i
        ><em class="GFGEditorTheme__textItalic">
          Seasons ENUM('Spring', 'Summer', 'Autumn', 'Winter')</em
        ></i
      >
    </p>
    <p>
      <i><em class="GFGEditorTheme__textItalic">);</em></i>
    </p>
    <h3><span>Practical Uses of Data Types</span></h3>
    <p dir="ltr">
      <b><strong>Data Integrity</strong></b
      ><span
        >: Using the correct data types can enforce data integrity by making
        sure only the correct types of data are inserted into tables.</span
      >
    </p>
    <p dir="ltr">
      <b><strong>Optimization</strong></b
      ><span
        >: Data types play a crucial role in optimizing storage and improving
        query performance.</span
      >
    </p>
    <p dir="ltr">
      <b><strong>Data Analysis</strong></b
      ><span
        >: Properly classified data is easier to analyze and manipulate, which
        is beneficial for data analytics and business intelligence.</span
      >
    </p>
    <h3><span>Summary</span></h3>
    <p dir="ltr">
      <span
        >Data types are integral in the understanding and effective manipulation
        of databases. They play a vital role in preserving data integrity,
        optimizing storage space, and facilitating effective data analysis. By
        understanding the different types of data, their uses, and their
        specific properties, one is better equipped to design and manage
        databases effectively.</span
      >
    </p>
  </div>
</div>
