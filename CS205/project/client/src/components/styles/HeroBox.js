import { styled } from '@mui/material/styles';
import Paper from '@mui/material/Paper';

const HeroBox = styled(Paper)(({ theme }) => ({
    backgroundColor: theme.palette.mode === 'dark' ? '#1A2027' : '#fff',
    ...theme.typography.body1,
    padding: theme.spacing(1),
    textAlign: 'center',
    color: 'white', /*theme.palette.text.primary,*/
    backgroundColor: '#008DC0' , /* '#296d98''#1c4966'*/
    height: '250px',
    paddingTop: '50px',
    
}));

export {HeroBox};