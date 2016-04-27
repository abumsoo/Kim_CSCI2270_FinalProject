from IPython.display import HTML
from bs4 import BeautifulSoup
import urllib

f = open('chars.txt', 'w')

r = urllib.urlopen('http://www.eventhubs.com/tiers/ssb4/').read()
soup = BeautifulSoup(r, "lxml")
characters = soup.find_all("td", class_="tierstdnorm")

count = 1
tierCharList=[]
for element in characters:
    if count==1:
        tier = element.get_text()
    elif count==2:
        character = element.get_text()
        tierChar = tier + "," + character
        tierCharList.append(tierChar)
    elif count%12==1:
        tier = element.get_text()
    elif count%12==2:
        character = element.get_text()
        tierChar = tier + "," + character
        tierCharList.append(tierChar)
    count+=1
tierCharList.remove(tierCharList[len(tierCharList)-1])

for x in range(0,len(tierCharList)):
    f.write(tierCharList[x])
    f.write("\n")
