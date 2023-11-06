function validate() {
  const pass1 = document.getElementById('pass1').value;
  const pass2 = document.getElementById('pass2').value;

  let valid = true;
  let alertMsg = '';
  if (pass1 !== pass2) {
    alertMsg += "Passwords don't match!\n";
    valid = false;
  }
  if (pass1.length < 8) {
    alertMsg += 'Password 1 is less than the required 8 characters\n';
    valid = false;
  }
  if (pass2.length < 8) {
    alertMsg += 'Password 2 is less than the required 8 characters\n';
    valid = false;
  }

  const msg = document.getElementById('msg');
  if (!valid) {
    msg.textContent = alertMsg;
  } else {
    msg.textContent = 'Passwords are valid';
  }

  return [valid, alertMsg];
}
