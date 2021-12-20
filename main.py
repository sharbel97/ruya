import cv2

# Access video device/webcam
camera = cv2.VideoCapture(0)
# camera.open('https://192.168.0.30:8080/video')
camera.set(3,1280)
camera.set(4,720)
camera.set(10,70)

classNames = []
classFile = 'labels.names'
with open(classFile, 'rt') as f:
    classNames = f.read().rstrip('\n').split('\n')

configPath = 'ssd_mobilenet_v3_large_coco_2020_01_14.pbtxt'
weightsPath = '../frozen_inference_graph.pb'

net = cv2.dnn_DetectionModel(weightsPath, configPath)
net.setInputSize(320, 320)
net.setInputScale(1.0/127.5)
net.setInputMean((127.5, 127.5, 127.5))
net.setInputSwapRB(True)

while True:
    # Getting frames from the webcam
    retrieve, frames = camera.read()

    height, width, _ = frames.shape

    classIds, confs, bbox = net.detect(frames, confThreshold=0.45)
    print(classIds, bbox)

    if len(classIds)!= 0:
        for classId, confidence, box in zip(classIds.flatten(), confs.flatten(), bbox):
            cv2.rectangle(frames, box, color=(0,255,0),thickness = 2)
            cv2.putText(frames, classNames[classId-1], (box[0]+10, box[1]+30), 
                        cv2.FONT_HERSHEY_COMPLEX,1,(0,255,0),2)
    
    # Setting up the frames into a UI window
    cv2.imshow('self', frames)


    # Closing the window on 'q' click
    if cv2.waitKey(20) & 0xFF == ord('q'):
        break;

camera.release()
cv2.destroyAllWindows()