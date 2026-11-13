# bike-sense
Bike Sense 🏍️⚡
Bike Sense is a React-based IoT dashboard designed to prevent your motorcycle's battery from dying. It monitors your bike's ignition and side stand sensors in real-time. If the bike is accidentally left powered on while parked on the stand, the app triggers a live warning alert and tracks the battery drain time.

✨ Features
Live Dashboard: Real-time visual feedback of Ignition/Battery and Side Stand status.
Drain Alert: Instantly displays a warning banner and starts a drain timer if the bike is left on while parked.
Hardware Simulator: Built-in toggles to simulate incoming IoT cellular data for testing the UI without physical hardware.
Responsive Design: Mobile-first layout crafted with Tailwind CSS for a premium look on any device.
🚀 Quick Start
Prerequisites
Make sure you have Node.js installed on your machine.

Installation
Clone the repository:

git clone https://github.com/yourusername/bike-sense.git
cd bike-sense
Set up a new React project (if you haven't already): Using Vite (Recommended):

npx create-vite . --template react
npm install
Install Dependencies: This project relies on lucide-react for icons and tailwindcss for styling.

npm install lucide-react
npm install -D tailwindcss postcss autoprefixer
npx tailwindcss init -p
Add the Component: Replace the contents of your App.jsx or App.js with the code provided in BikeSense.jsx.

Start the Development Server:

npm run dev
🛠️ Tech Stack
React - UI Component & State Management
Tailwind CSS - Styling and Animations
Lucide React - Iconography
📄 License
This project is licensed under the MIT License - see the LICENSE file for details.