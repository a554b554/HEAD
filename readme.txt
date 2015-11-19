The core function of head reconstruction from image is in "HeadGenerator" folder.
However it need facial landmarks (76 landmarks), which can be generated in
various ways, for an example, I here provide a warpper of STASM library
(including a binary version for Windows X86 platform, you can also compile the
latest version from its website) in the folder "HeadDetector".

The code require OpenCV and Qt library, but can be easily replaced if necessary.

With my provided classes, to generate the head model, the example code is:

	// Detect 76 landmarks
	// If they are not accurate, try to manually adjust their locations

	HeadDetector detector;
	// m_targetImage is the original image
	detector.setOriginalImage(m_targetImage);
	// Detect landmarks
	detector.runDetect();

	// Reconstruct the head

	HeadGenerator fitter;
	// The head mesh
	// can export it to obj format via saveModel(filename) function
	MeshModel headModel;
	fitter.reset();
	// Set image width & height
	fitter.setSize(m_targetImage.cols, m_targetImage.rows);
	// Set the landmarks
	fitter.setFeatures(&detector.getResultFeatures());
	// Give the target mesh
	fitter.setHeadModel(headModel);
	// Generate the mesh, write to headModel
	fitter.runHeadGenerate();