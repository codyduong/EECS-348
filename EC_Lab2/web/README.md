# Extra Credit Lab 2 - Dockerize Web Application

```bash
# build and test
docker build -t mywebapp .
docker run -d -p 8080:80 --name mywebapp-container mywebapp
# deploys to http://localhost:8080 

# push to docker
docker login
docker tag mywebapp codyduong/eecs348_eclab2_web:latest
docker push codyduong/eecs348_eclab2_web:latest
docker logout

# build and test remote
docker pull codyduong/eecs348_eclab2_web:latest
docker run -p 8080:80 codyduong/eecs348_eclab2_web:latest
```