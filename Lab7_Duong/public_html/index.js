const path = window.location.pathname;

const pathSegments = path.split('/').filter((segment) => segment !== '')

const ul = document.createElement('ol');

pathSegments.forEach((segment, i) => {
  const li = document.createElement('li');
  li.className = 'crumb';
  if (i === pathSegments.length - 1) {
    li.textContent = segment;
    ul.appendChild(li);
    return;
  }
  const a = document.createElement('a');
  a.href = `/${pathSegments.slice(0, i - 1).join('/')}`;
  a.textContent = segment;
  a.rel = "noreferrer";
  li.appendChild(a);
  ul.appendChild(li);
});

const navElement = document.getElementById('nav');
navElement.className += 'crumbs';
navElement.innerHTML = '';
navElement.appendChild(ul);
