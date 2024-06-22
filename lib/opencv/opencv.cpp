#include <gstream.h>
#include <opencvLib.h>

void objectDetection(gint width, gint height, guint8 *data) {
    // Path to the haarcascade file
    std::string cascadePath = "C:/msys64/mingw64/share/opencv4/haarcascades/haarcascade_frontalface_default.xml";
    
    cv::CascadeClassifier faceDetectorYN;
    if(!faceDetectorYN.load(cascadePath)) {
        std::cerr << "Error loading face cascade from " << cascadePath << std::endl;
    }

    // Convert GStreamer buffer to OpenCV Mat
    cv::Mat frame(height, width, CV_8UC3, data);
    if(frame.empty()) {
        std::cerr << "Could not open or find the frame" << std::endl;
    }

    // Process the frame using OpenCV (for example, convert to grayscale)
    cv::Mat gray_frame;
    cv::cvtColor(frame, gray_frame, cv::COLOR_RGB2GRAY);

    std::vector<cv::Rect> faces;
    faceDetectorYN.detectMultiScale(gray_frame, faces);

    for(size_t i=0; i < faces.size(); i++) {
        rectangle(frame, faces[i], cv::Scalar(255, 0, 0), 2);
    }


    // std::cout << cv::getBuildInformation() << std::endl;
    // cv::namedWindow("Webcam", cv::WINDOW_AUTOSIZE | cv::WINDOW_GUI_EXPANDED);

    // cv::namedWindow("Webcam", cv::WINDOW_NORMAL);

    // Display the frame using OpenCV
    cv::imshow("Webcam", frame);
    cv::waitKey(1); // Required to keep the window open and process events
    cv::destroyAllWindows();
}

void faceDetection() {
    std::string cascadePath = "C:/msys64/mingw64/share/opencv4/haarcascades/haarcascade_frontalface_default.xml";
    std::string cascadePathEye = "C:/msys64/mingw64/share/opencv4/haarcascades/haarcascade_eye.xml";

    std::string path = cascadePathEye;
    
    cv::CascadeClassifier faceDetectorYN;
    if(!faceDetectorYN.load(path)) {
        std::cerr << "Error loading face cascade from " << path << std::endl;
    }
    // Open video capture from the default webcam (usually the first webcam device)
    cv::VideoCapture cap(0);

    // Check if the video capture opened successfully
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open video capture." << std::endl;
    }

    // Create a named window
    cv::namedWindow("Webcam Video", cv::WINDOW_KEEPRATIO);

    while (true) {
        // Capture frame-by-frame
        cv::Mat frame;
        cap >> frame;

        // Check if frame is read correctly
        if (frame.empty()) {
            std::cerr << "Error: Could not read frame." << std::endl;
            break;
        }

        std::vector<cv::Rect> faces;
        faceDetectorYN.detectMultiScale(frame, faces);

        for(size_t i=0; i < faces.size(); i++) {
            rectangle(frame, faces[i], cv::Scalar(255, 0, 0), 2);
        }


        // Display the frame in the window
        cv::imshow("Webcam Video", frame);

        // Break the loop on 'q' key press
        if (cv::waitKey(1) == 'c') {
            break;
        }
    }

    // Release the video capture and close windows
    cap.release();
    cv::destroyAllWindows();
}