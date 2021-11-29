import './App.css';
import './Button.css';
import { BrowserRouter as Router, Switch, Route } from 'react-router-dom';
import Login from './Login';
import Navbar from './Navbar';
import Home from './Home';
import RobotSelector from './RobotSlector';


function App() {
  return ( 
    <>
    <Router>
      <Navbar />
      <Switch>
        <Route path='/' exact component={Home} />
        <Route path='/Login' exact component={Login} />
        <Route path='/RobotSelector' exact component={RobotSelector} />
      </Switch>
    </Router>
    </>
  );
}

export default App;
