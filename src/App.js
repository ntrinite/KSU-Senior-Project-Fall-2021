import './App.css';
import './Button.css';
import { BrowserRouter as Router, Switch, Route } from 'react-router-dom';
import Login from './Login';
import Navbar from './Navbar';
import Footer from './Footer';
import Home from './Home';


function App() {
  return ( 
    <>
    <Router>
      <Navbar />
      <Switch>
        <Route path='/' exact component={Home} />
        <Route path='/Login' exact component={Login} />
      </Switch>
    </Router>
    </>
  );
}

export default App;
