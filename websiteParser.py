from lxml import html
import requests

page = requests.get('http://www.ssbwiki.com/Category:Characters_(SSB4)')
tree = html.fromstring(page.content)
moves = tree.xpath('//[@=""]/()')

# print (page.json())

print ('Moves: ', moves)
