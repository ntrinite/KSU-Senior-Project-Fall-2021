var app = new Vue({
    el: '#app',
    data: {
      connected: false,
      ros: null,
      ws_address: '', // this is my problem
      topic: null,
      message: null
  
    },
  
    methods: {
        connect: function(){

            
            console.log('Connecting...');

            this.ros = new ROSLIB.Ros({
              url : this.ws_address
            });
            this.ros.on('connection', () => {
              console.log('Connected!');
              this.connected = true;
            });
          
            this.ros.on('error', (error) => {
              console.log('Error connecting to websocket server: ', error);
            });
          
            this.ros.on('close', () => {
              console.log('Connection to websocket server closed.');
              this.connected = false;
            })
        },
  
        disconnect: function(){
            console.log('Disconnecting...');
            this.ros.close();
        },
  
        setTopic: function(){
          this.topic = new ROSLIB.Topic({
            ros : this.ros,
            name : '/cmd_vel',
            messageType : 'geometry_msgs/Twist'
          })
        },
  
        // Get both wheels to move
        goForward: function(){
          this.message = new ROSLIB.Message({
            linear : {
              x : 1,
              y : 0,
              z : 0
            },
            angular : {
              x : 0,
              y : 0,
              z : 0
            }
          });
          this.setTopic();
          this.topic.publish(this.message);
        },
        
        // Get only the right wheel to move
        goLeft: function(){
          this.message = new ROSLIB.Message({
            linear : {
              x : 0.5,
              y : 0,
              z : 0
            },
            angular : {
              x : 0,
              y : 0,
              z : 0.5
            }
          });
          this.setTopic();
          this.topic.publish(this.message);
        },
        
        // Get only the left wheel to move
        goRight: function(){
          this.message = new ROSLIB.Message({
            linear : {
              x : 0.5,
              y : 0,
              z : 0
            },
            angular : {
              x : 0,
              y : 0,
              z : -0.5
            }
          });
          this.setTopic();
          this.topic.publish(this.message);
        },
        
        // Move backwards if our bot allows it
        goBack: function(){
          this.message = new ROSLIB.Message({
            linear : {
              x : -1,
              y : 0,
              z : 0
            },
            angular : {
              x : 0,
              y : 0,
              z : 0
            }
          });
          this.setTopic();
          this.topic.publish(this.message);
        },
  
        // Stop the movements
        goStop: function(){
          this.message = new ROSLIB.Message({
            linear : {
              x : 0,
              y : 0,
              z : 0
            },
            angular : {
              x : 0,
              y : 0,
              z : 0
            }
          });
          this.setTopic();
          this.topic.publish(this.message);
        }
        
  
      }
  })