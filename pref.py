import requests

food = requests.get("https://young-garden-40398.herokuapp.com/api/food")

print food.json()
