import os
import time
import threading
from appJar import gui
from dotenv import load_dotenv
from datetime import datetime, timedelta
from pyicloud import PyiCloudService
load_dotenv()

ICLOUD_USERNAME = os.getenv("ICLOUD_USERNAME")
ICLOUD_PASSWORD = os.getenv("ICLOUD_PASSWORD")

api = PyiCloudService(ICLOUD_USERNAME,ICLOUD_PASSWORD)


app = gui("ICLOUD MANAGER")
def getEvents():
    if not api.calendar:
        return ["CAL ACESS NOT AVAILABLE"]
    now = datetime.now()
    end_of_day = now.replace(hour=23,minute=59,second=59)
    events = api.calendar.events(now,end_of_day)
    event_list = []
    for event in events:
        start_time = event.get("startDate")
        summary = event.get("title")
        start_dt = datetime.fromtimestamp(start_time.timestamp())
        event_list.append(f"{start_dt.strftime('%H:%M')} - {summary}")
    return event_list if event_list else ["No events today"]
def refresh_events():
    events = getEvents()
    app.clearListBox("eventList")
    app.updateListBox("eventList",events)
    
def sendSummary():
    events = getEvents()
    summary = "\n".join(events)
    
    if summary:
        api.devices[0].display_message("Hourly Event Message",summary)
        app.infoBox("Sucess","Hourly Message Sent")
def hourlySummary():
    while True:
        sendSummary()
        time.sleep(3600) 
app.addLabel("title","icloud cal manager",0,0,2)
app.addListBox("eventList",[],1,0,2,rowspan=4)
app.addButton("Refresh Events", refresh_events, 5, 0)
app.addButton("Send Summary Now", sendSummary, 5, 1)

app.go()
