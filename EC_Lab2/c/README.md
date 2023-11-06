# Extra Credit Lab 2 - Dockerize C Application

```bash
# build and test
docker build -t mycprogram .
docker run -it --name mycprogram-container mycprogram

# push to docker
docker login
docker tag mycprogram codyduong/eecs348_eclab2_c:latest
docker push codyduong/eecs348_eclab2_c:latest
docker logout

# build and test remote
docker pull codyduong/eecs348_eclab2_c:latest
docker run -it codyduong/eecs348_eclab2_c:latest
```