To run server:

1. run rmiregistry
2. java -Djava.rmi.server.codebase=file:///[path-to-dist]/server.jar -Djava.security.policy=policy -jar dist/server.jar 



To run client:

1. run server from lab3
2. java -Djava.security.policy=policy -jar dist/client.jar 


