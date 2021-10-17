import React, {useState} from 'react'
import { Link } from 'react-router-dom'
import { Button } from './Button';
import './Navbar.css'


function Navbar() {
    const [click, setClick] = useState(false);
    const [button, setButton] = useState(true);

    const handleClick = () => setClick(!click);
    const closeMobileMenu = () => setClick(false);

    const showButton = () => {
        if (window.innerWidth <= 960) {
          setButton(false);
        } else {
          setButton(true);
        }
      };
    
     
    
    window.addEventListener('resize', showButton);

    return (
        <>
            <nav className="Navbar">
                <div className="navbar-container">
                    <Link to="/" className="navbar-logo">
                        Remote Presence Robot <i className='fab fa-typo3' />
                    </Link>
                    <div className='menu-icon'>
                        <i className={click ? 'fas fa-times' : 'fas fa-bars'} />
                        </div>
                        <ul className={click ? 'nav-menu active' : 'nav-menu'}>
                            <li className='nav-item'>
                                <Link to='/' className='nav-links' onClick={closeMobileMenu}>
                                    Home
                                </Link>
                            </li>
                            <li className='nav-item'>
                                <Link to='/' className='nav-links' onClick={closeMobileMenu}>
                                    Services
                                </Link>
                            </li>
                            <li className='nav-item'>
                                <Link to='/' className='nav-links' onClick={closeMobileMenu}>
                                    Products
                                </Link>
                            </li>
                            <li className='nav-item'>
                                <Link to='/Login' className='nav-links' onClick={closeMobileMenu}>
                                    Login
                                </Link>
                            </li>
                        </ul> 
                        
                    </div>
            </nav>
        </>
    )
}

export default Navbar;
