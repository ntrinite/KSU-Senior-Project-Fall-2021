;; Auto-generated. Do not edit!


(when (boundp 'movement::Control)
  (if (not (find-package "MOVEMENT"))
    (make-package "MOVEMENT"))
  (shadow 'Control (find-package "MOVEMENT")))
(unless (find-package "MOVEMENT::CONTROL")
  (make-package "MOVEMENT::CONTROL"))

(in-package "ROS")
;;//! \htmlinclude Control.msg.html


(defclass movement::Control
  :super ros::object
  :slots (_direction _do_move ))

(defmethod movement::Control
  (:init
   (&key
    ((:direction __direction) 0)
    ((:do_move __do_move) nil)
    )
   (send-super :init)
   (setq _direction (round __direction))
   (setq _do_move __do_move)
   self)
  (:direction
   (&optional __direction)
   (if __direction (setq _direction __direction)) _direction)
  (:do_move
   (&optional __do_move)
   (if __do_move (setq _do_move __do_move)) _do_move)
  (:serialization-length
   ()
   (+
    ;; int16 _direction
    2
    ;; bool _do_move
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16 _direction
       (write-word _direction s)
     ;; bool _do_move
       (if _do_move (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16 _direction
     (setq _direction (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; bool _do_move
     (setq _do_move (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get movement::Control :md5sum-) "31f19f0cdb5988f5b529a515002930fb")
(setf (get movement::Control :datatype-) "movement/Control")
(setf (get movement::Control :definition-)
      "int16 direction
bool do_move
")



(provide :movement/Control "31f19f0cdb5988f5b529a515002930fb")


