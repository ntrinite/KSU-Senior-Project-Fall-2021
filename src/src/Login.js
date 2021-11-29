import React, { Component } from "react";
import './Login.css';


export default class Login extends Component {
    render() {
        return (
          <div className="flex-container">
            <form>
                
                <h3>Sign In</h3>

                <div className="form-group">
                    <label>Email address</label>
                    <br />
                    
                    <input type="email" className="form-control" placeholder="Enter email" />
                </div>
                <br />
                <div className="form-group">
                    <label>Password</label>
                    <br />
                    <input type="password" className="form-control" placeholder="Enter password" />
                </div>
                <br />
                <div className="form-group">
                    <div className="custom-control custom-checkbox">
                        <input type="checkbox" className="custom-control-input" id="customCheck1" />
                        <label className="custom-control-label" htmlFor="customCheck1">Remember me</label>
                    </div>
                </div>

                <button type="submit" className="btn btn-primary btn-block"> <a href="/RobotSelector">Submit</a></button>
                <p className="forgot-password text-right">
                    Forgot <a href="#">password?</a>
                </p>
                
            </form>
          </div>
        );
    }
}