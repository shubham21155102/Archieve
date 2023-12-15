## Video Transcoding Service

**Examples**

- Youtube
- Udemy
- Unacdemy

```mermaid
graph LR;
A[Teacher]-- Upload --> B[Video]
C[Student]-- Request <-->B
```

```mermaid
graph LR;
A[Teacher] -- Hey Lambda Function I want to upload 10 videos --> λ
λ -- Returns Signed URL Of S3 bucket -->A
```

- Now Teacher If Authorised
- Now a S3 Temporary Bucket is formed using Signed URL

```mermaid
graph LR; 
A[TEACHER]--Uploading 10 videos -->B[S3 Temprary Bucket]
```

[//]: # (```mermaid)

[//]: # (zenuml)

[//]: # (    @Actor Teacher)

[//]: # (    @S3 S3Bucket)

[//]: # (    @Lambda LambdaFunction        )

[//]: # (```)
- An EventBridge set up is present on this Bucket

```mermaid
graph LR;
A[EventBridge]--Triggers a lambda function -->λ
λ-->X[Queue Jobs] 
```

- Let's say Queue job has 5 video processing limit
```mermaid
graph LR;
A[Queue Jobs]--5 Jobs-->B[Video Processing]
 ```
- Now Video Processing is done by Lambda Function
- Redis Based Queue is used to store the jobs
- Now lets say we have 5 lambda functions
- Each lambda function can process 5 videos at a time
- So we can process 25 videos at a time
```mermaid
graph LR;
A[Queue Jobs]--5 Jobs-->B[Video Processing :Consumer]
```
```mermaid
graph LR;
    A[Consumer] --> B[Redis:No. of video is processing=0]
    B -- 0 vides processing <-->A
    A-- 5 jobs from queue -->B
    X[5 AWS -ECS Containers]-- 5 jobs from queue -->X
    C1[AWS ECS Bucket 1:ubuntu running in this bucket]
    C2[AWS ECS Bucket 2:ubuntu running in this bucket]
    C3[AWS ECS Container 3:ubuntu running in this bucket]
    C4[AWS ECS Container 4:ubuntu running in this bucket]
    C5[AWS ECS Container 5:ubuntu running in this bucket]
    C1 --> Y[FFMPEG:1080,720,480,360,240,144]
    C2 --> Y    
    C3 --> Y
    C4 --> Y
    C5 --> Y
    Y -->ZZ[Storage Bucket]
```
- Now temporary bucket is deleted