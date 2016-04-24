from lxml import html
import requests

page = requests.get('http://www.eventhubs.com/moves/ssb4/')
tree = html.fromstring(page.content)
moves = tree.xpath('//span[@style="font-size:16px;padding-left:5px;"]/text()')

# print (page.json())

print ('Moves: ', moves)
