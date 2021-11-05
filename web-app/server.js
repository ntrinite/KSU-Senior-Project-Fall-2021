const express = require('express')
const app = express()
const server = require('http').Server(app)
const io = require('socket.io')(server)
const { v4: uuidV4 } = require('uuid')

app.set('view engine', 'ejs')
app.use('/', express.static('public'))

app.get('/', (req, res) => {
	res.redirect(`/project/${uuidV4()}`)
})

app.get('/:room', (req, res) => {
	res.render('room', { roomId: req.params.room })
})

io.on('connection', socket => {
	console.log('socket connection initialized');
	socket.on('join-room', (roomId, userId) => {
		socket.join(roomId)
		console.log(roomId);
		socket.broadcast.to(roomId).emit('user-connected', userId)

		socket.on('disconnect', () => {
			socket.broadcast.to(roomId).emit('user-disconnected', userId)
		})
	})
})

server.listen(8090)
