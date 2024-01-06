!pip install grpcio-tools protobuf
python3 -m grpc.tools.protoc -I=. --python_out=. --grpc_python_out=. calculator.proto