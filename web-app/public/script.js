const socket = io('/');
const videoGrid = document.getElementById('video-grid');
const smallWindow = document.getElementById('small-window');
const myPeer = new Peer();

const myVideo = document.createElement('video');
myVideo.muted = true;
const peers = {};

myPeer.on('open', id => {
	console.log('my id: ' + id);
	console.log('room id: ' + ROOM_ID);
	socket.emit('join-room', ROOM_ID, id)
});

navigator.mediaDevices.getUserMedia({ 
	video: true,
	audio: true
}).then(stream => {
	addToSmallWindow(myVideo, stream)

	myPeer.on('call', call => {
		console.log(call)
		call.answer(stream)
		const video = document.createElement('video')
		call.on('stream', userVideoStream => {
			console.log('hello')
			addVideoStream(video, userVideoStream);
		})
	})

	socket.on('user-connected', userId => {
		console.log('user-connected: ' + userId);
		setTimeout(connectToNewUser, 500, userId, stream)
	})

	socket.on('user-disconnected', userId => {
		console.log('user-disconnected: ' + userId);
		if (peers[userId]) peers[userId].close()
	})
})

function connectToNewUser(userId, stream) {
	console.log('connect to ' + userId + '...')
	console.log(stream)
	const call = myPeer.call(userId, stream)
	const video = document.createElement('video')
	call.on('stream', userVideoStream => {
		console.log('hello')
		addVideoStream(video, userVideoStream)
	})
	call.on('close', () => {
		console.log('removed')
		video.remove()
	})

	peers[userId] = call
}

function addVideoStream(video, stream) {
	video.srcObject = stream
	video.addEventListener('loadedmetadata', () => {
		video.play()
	})
	let p = document.getElementById("waiting");
	p.parentNode.removeChild(p);
	videoGrid.value = "";
	videoGrid.style.backgroundColor = "#FFE4C4";
	videoGrid.append(video)
}

function addToSmallWindow(video, stream) {
	video.srcObject = stream
	video.addEventListener('loadedmetadata', () => {
		video.play()
	})
	smallWindow.append(video)
}
