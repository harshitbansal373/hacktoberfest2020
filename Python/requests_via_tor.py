"""
This is an example how you can use Python requests library together with TOR as proxy.
To perform HTTP requests via TOR, you need TOR running on your machine.
One of the ways to achieve this is to setup and launch TOR browser.
"""

import requests

# check if your TOR port is correct as it may change with time
tor_port = 9150
p = {
    'http': f"socks5://localhost:{tor_port}",
    'https': f"socks5://localhost:{tor_port}"
}

test_url = 'http://httpbin.org/ip'

print("Original IP:")
print(requests.get(test_url).text)
print("IP with Tor proxy:")
print(requests.get(test_url, proxies = p).text)
