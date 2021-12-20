import cv2

# Access video device/webcam
camera = cv2.VideoCapture(0)
# camera.open('https://192.168.0.30:8080/video')

# Object detection from Stable camera
object_detector = cv2.createBackgroundSubtractorMOG2(history=100, varThreshold=40)

while True:
    # Getting frames from the webcam
    retrieve, frames = camera.read()

    height, width, _ = frames.shape
    
    # Setting up the frames into a UI window
    cv2.imshow('self', frames)


    # Closing the window on 'q' click
    if cv2.waitKey(20) & 0xFF == ord('q'):
        break;

camera.release()
cv2.destroyAllWindows()