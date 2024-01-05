// Function to update the images
function updateImages() {
  const imageElements = document.querySelectorAll('.image-viewer');
  
  imageElements.forEach((imageElement, index) => {
    // Randomly generate a timestamp to bypass browser cache
    const timestamp = new Date().getTime();
    
    // Get the current image source
    const currentSrc = imageElement.src;
    
    // Extract the base URL (string before the question mark)
    const baseUrl = currentSrc.split('?')[0];
    
    // Set the image source with the timestamp to fetch the updated image
    imageElement.src = `${baseUrl}?timestamp=${timestamp}`;
  });
}

// Update the images every 0.1 seconds (100 milliseconds)
setInterval(updateImages, 100);
