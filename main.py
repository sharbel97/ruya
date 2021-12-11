import cv2

# Access video device/webcam
camera = cv2.VideoCapture(0)

while True:
    # Getting frames from the webcam
    retrieve, frames = camera.read()
    
    # Setting up the frames into a UI window
    cv2.imshow('self', frames)

    # Closing the window on 'q' click
    if cv2.waitKey(20) & 0xFF == ord('q'):
        break;
        