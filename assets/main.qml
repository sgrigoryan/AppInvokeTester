import bb.cascades 1.0

Page {
    Container {
        minHeight: 720
        Button {
            id: invokeButton
            text: "Invoke Twitter"
  
            verticalAlignment: VerticalAlignment.Center
            horizontalAlignment: HorizontalAlignment.Center
            onClicked: {
                _controller.invokeTwitterApp();
                invokeButton.enabled = false
            }
        }
    }
}
