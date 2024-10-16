// Define constants for rate limiting
const MAX_REQUESTS_PER_SECOND = 10;
const TIME_WINDOW = 1000; // 1 second in milliseconds

// Map to store user request timestamps
const userRequests = {};

// Function to check if a user is within the rate limit
function isRateLimited(userId) {
    const currentTime = Date.now();

    // Initialize the user request log if not present
    if (!userRequests[userId]) {
        userRequests[userId] = [];
    }

    // Get the user's request log
    const requestLog = userRequests[userId];

    // Remove requests that are outside the time window (older than 1 second)
    while (requestLog.length > 0 && requestLog[0] <= currentTime - TIME_WINDOW) {
        requestLog.shift(); // Automatically delete old timestamps
    }

    // Check if the user has exceeded the request limit
    if (requestLog.length >= MAX_REQUESTS_PER_SECOND) {
        return true; // Rate limit exceeded
    } else {
        // Add the current timestamp to the request log
        requestLog.push(currentTime);
        return false; // Rate limit not exceeded
    }
}

// Function to clear inactive users after a period of time (e.g., 5 seconds of inactivity)
function clearInactiveUsers() {
    const currentTime = Date.now();
    
    for (let userId in userRequests) {
        const requestLog = userRequests[userId];

        // If the last request was outside of the TIME_WINDOW + some buffer (e.g., 5 seconds)
        if (requestLog.length === 0 || requestLog[requestLog.length - 1] <= currentTime - (TIME_WINDOW + 5000)) {
            delete userRequests[userId]; // Clean up inactive user logs
        }
    }
}

// Example usage
function handleRequest(userId) {
    if (isRateLimited(userId)) {
        console.log(`Rate limit exceeded for user: ${userId}`);
        // Return 429 status code or handle as needed
    } else {
        console.log(`Request allowed for user: ${userId}`);
        // Proceed with handling the request
    }
}

// Periodically clear inactive users (optional, for auto-cleanup)
setInterval(clearInactiveUsers, 60000); // Clear inactive users every minute

// Simulate incoming requests for user "user123"
setInterval(() => {
    handleRequest("user123");
}, 10); // 1 request every 10ms (10 requests per second)