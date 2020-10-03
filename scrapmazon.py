import bs4
import urllib.request
import smtplib
import time


prices_list=[]

def check_price():
    url = 'https://www.amazon.in/Samsung-Galaxy-Ocean-128GB-Storage/dp/B07HGGYWL6/ref=sr_1_1?dchild=1&keywords=poco+x2&qid=1598001158&sr=8-1'
    sauce= urllib.request.urlopen(url).read()
    soup = bs4.BeautifulSoup(sauce,"html.parser")
    prices = soup.find(id="priceblock_ourprice").get_text()
    prices = float(prices.replace(",","").replace("₹",""))
    prices_list.append(prices)
    return prices

def send_email(message):
    s= smtplib.SMTP('smtp.gmail.com',587)
    s.starttls()
    s.login("fazinmohammed30@gmail.com","geyjxcywsbxpdeet")
    s.sendmail("fazinmohammed30@gmail.com","sheehaanwahid@gmail.com",message)
    s.quit()
send_email("HELLO")    


def price_decrease_check(price_list):
    if prices_list[-1] < prices_list[-2]:
        return True
    else:
        return False    

count = 1
while True:
    current_price = check_price()
    if count > 1:
        flag = price_decrease_check(prices_list)
        if flag:
            decrease= prices_list[-1] - prices_list[-2]
            message= "PRICE DECREASED CHECK! . The price decreased by {decrease} rupees.Check https://www.amazon.in/Samsung-Galaxy-Ocean-128GB-Storage/dp/B07HGGYWL6/ref=sr_1_1?dchild=1&keywords=poco+x2&qid=1598001158&sr=8-1"
            send_email(message)
    time.sleep(43000)
    count += 1        