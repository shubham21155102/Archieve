# Building Own RTMP Server

## Overview

This project documents the development and integration of a custom RTMP (Real-Time Messaging Protocol) server aimed at facilitating video streaming for an AI interview platform. It outlines the motivations behind the decision to build a proprietary solution, the challenges faced with existing services, and the successful implementation of the custom RTMP server.

## Motivation

During an internship at **_Acencore_**, the task of developing an AI interview platform was assigned. Among the pivotal requirements was the seamless streaming of video content from the browser to the server. This necessitated the exploration of various streaming solutions.

## Challenges Faced

Initial attempts involved leveraging **_YouTube's RTMP server_**, which presented limitations in terms of control over video content. Consequently, transition to **_Amazon's Interactive Video Service (IVS)_** was considered. However, the associated costs posed a significant barrier to adoption.

## Solution

To address the challenges encountered with existing solutions, the decision was made to construct a custom RTMP server tailored to the project's specific requirements. This endeavor involved the development of requisite infrastructure and protocols to ensure smooth and efficient video streaming.

## Implementation

The custom RTMP server was successfully implemented and seamlessly integrated into the project workflow. This solution not only mitigated cost concerns but also provided enhanced control and flexibility over the streaming process. The platform achieved its objectives of real-time video streaming and integration with machine learning analysis.

### Working Parts

To ensure the successful implementation of the custom RTMP server, several components and configurations were utilized. Below are the key working parts involved in the process:

- **EC2 Instance Setup**: An EC2 instance was provisioned on AWS to serve as the host for the RTMP server.

- **OBS Installations**: OBS (Open Broadcaster Software) was installed on the EC2 instance to facilitate video streaming. The following commands were executed for installation:

  ```bash
  sudo apt install v4l2loopback-dkms

  sudo apt install ffmpeg

  sudo add-apt-repository ppa:obsproject/obs-studio

  sudo apt update

  sudo apt install obs-studio
  ```

- **Nginx Installation**: Nginx, a high-performance web server, was installed on the EC2 instance to handle RTMP streaming. The installation process involved the following steps:

  ```bash
  sudo apt update

  sudo apt install nginx

  sudo apt install libnginx-mod-rtmp

  sudo systemctl start nginx

  sudo systemctl enable nginx

  sudo vi /etc/nginx/nginx.conf
  ```

- **Configuration of Nginx for RTMP**: The Nginx configuration file was edited to include settings specific to RTMP streaming. The following lines were added to the configuration file:

  ```nginx
  rtmp {
      server {
          listen 1935;
          chunk_size 4096;
          allow publish all;

          application live {
              live on;
              record off;
          }
      }
  }
  ```

- **Opening Port 1935**: To allow incoming connections on port 1935 for RTMP streaming, the firewall settings were adjusted:

  ```bash
  sudo ufw allow 1935/tcp
  ```

- **Starting Nginx Service**: The Nginx service was started to enable RTMP streaming:

  ```bash
  sudo systemctl restart nginx
  ```

- **Checking 1935 Port**: The status of port 1935 was verified to ensure that the RTMP server was running:

  ```bash
  ss -antpl | grep 1935
  ```

- Now I just wrote code and added rtmp url as rtmp://**.\***.**.**/ (IP address of the EC2 instance)

## Configure RTMP Statistics for Monitoring

Once your RTMP server is installed and operational, it's crucial to set up the RTMP statistics page to monitor your streaming activities effectively. Follow the steps below to configure the RTMP statistics page:

### 1. Create Directory for RTMP Stat File

First, create a directory to store the RTMP stat file using the following command:

```bash
mkdir /var/www/html/rtmp
```

### 2. Copy RTMP Stat File

Next, copy the RTMP stat file to the created directory:

```bash
cp /usr/share/doc/libnginx-mod-rtmp/examples/stat.xsl /var/www/html/rtmp/stat.xsl
```

### 3. Edit Nginx Virtual Host Configuration

Edit the Nginx default virtual host configuration file:

```bash
nano /etc/nginx/sites-available/default
```

Remove all default lines and replace them with the following configuration:

```nginx
server {
    listen 8080;
    server_name  _;

    # RTMP stat
    location /stat {
        rtmp_stat all;
        rtmp_stat_stylesheet stat.xsl;
    }
    location /stat.xsl {
        root /var/www/html/rtmp;
    }

    # RTMP control
    location /control {
        rtmp_control all;
    }
}
```

Save and close the file.

### 4. Restart Nginx Service

Restart the Nginx service to apply the changes:

```bash
systemctl restart nginx
```

### 5. Access RTMP Stat Page

Now, open your web browser and navigate to the RTMP stat page using the URL `http://your-server-ip:8080/stat`. You should be able to view the RTMP statistics on the displayed page.

Remember to refresh the page every time you stream a video to observe changes in the stream statistics effectively.

These components and configurations collectively enabled the establishment of a custom RTMP server, facilitating seamless video streaming for the AI interview platform.

## Conclusion

The development and integration of the custom RTMP server proved instrumental in the success of the AI interview platform at Acencore. This initiative not only addressed the immediate project requirements but also demonstrated innovation and problem-solving capabilities.
