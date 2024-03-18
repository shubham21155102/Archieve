# Jenkins

Jenkins is an open source automation server written in Java. Jenkins helps to automate the non-human part of the software development process, with continuous integration and facilitating technical aspects of continuous delivery. It is a server-based system that runs in servlet containers such as Apache Tomcat. It supports version control tools, including AccuRev, CVS, Subversion, Git, Mercurial, Perforce, ClearCase and RTC, and can execute Apache Ant, Apache Maven and sbt based projects as well as arbitrary shell scripts and Windows batch commands. The creator of Jenkins is Kohsuke Kawaguchi. Released under the MIT License, Jenkins is free software.

## Installation(Mac OS)

- `brew install jenkins-lts`
- `brew services start jenkins-lts`
- `cat /Users/Shared/Jenkins/Home/secrets/initialAdminPassword`
- Open browser and go to http://localhost:8080
- Error resolve in MacOS
  - [Error Resolve](https://medium.com/@bectorhimanshu/fix-for-the-error-docker-command-not-found-when-building-docker-image-using-jenkins-pipeline-on-db1bc5fa7976)
- Jenkins is ready to use

## Resolving "Docker command not found" Error in Jenkins Pipeline on macOS

This issue commonly occurs in Jenkins Pipeline on macOS when the Docker command is not found due to it not being installed or not being available in the system's PATH. To resolve this issue, follow these steps:

### Step 1: Find Jenkins Installation Directory

1. Open Terminal.
2. Run the following command to find the Jenkins installation directory:

```bash
brew --prefix jenkins
```

- Note down the output path, which typically looks like /opt/homebrew/opt/jenkins-lts.

### Step 2: Update Jenkins Launch Configuration

Locate the file homebrew.mxcl.jenkins-lts.plist in the Jenkins installation directory found in Step 1 (/opt/homebrew/opt/jenkins-lts).
Update the content of the file as follows:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>Label</key>
    <string>homebrew.mxcl.jenkins-lts</string>
    <key>ProgramArguments</key>
    <array>
        <string>/opt/homebrew/opt/openjdk@17/bin/java</string>
        <string>-Dmail.smtp.starttls.enable=true</string>
        <string>-jar</string>
        <string>/opt/homebrew/opt/jenkins-lts/libexec/jenkins.war</string>
        <string>--httpListenAddress=127.0.0.1</string>
        <string>--httpPort=8080</string>
    </array>
    <key>RunAtLoad</key>
    <true/>
    <key>EnvironmentVariables</key>
    <dict>
        <key>PATH</key>
        <string>/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Applications/Docker.app/Contents/Resources/bin/:/Users/himanshubector/Library/Group\ Containers/group.com.docker/Applications/Docker.app/Contents/Resources/bin</string>
    </dict>
</dict>
</plist>
```

### Step 3: Restart Jenkins

After updating the file, restart Jenkins using the following brew command:

```bash
brew services restart jenkins-lts
```

### Step 4: Verify

- Try running the Jenkins Pipeline build again. After following these steps, your Jenkins Pipeline on macOS should be able to find and use Docker for building Docker images without encountering the "Docker command not found" error.
