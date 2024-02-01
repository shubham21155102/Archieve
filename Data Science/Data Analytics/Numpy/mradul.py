import requests
import concurrent.futures
import time

API_ENDPOINT = "https://api.ostello.co.in/institute"

def make_request(url):
    start_time = time.time()
    response = requests.get(url)
    end_time = time.time()

    response_time = end_time - start_time
    status_code = response.status_code

    print(f"URL: {url}+"", Response Time: {response_time:.4f} seconds, Status Code: {status_code}")

num_requests = 20000

urls = [f"{API_ENDPOINT}" for i in range(num_requests)]

with concurrent.futures.ThreadPoolExecutor() as executor:
    executor.map(make_request,urls)
    