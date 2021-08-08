terraform {
  required_providers {                  # Terraform üzerinden dockerhub indirme işlemi.
    docker = {
      source  = "kreuzwerker/docker"    # Link      :https://registry.terraform.io/providers/kreuzwerker/docker/latest
      version = "2.14.0"                # Version   : 2.14.0
    }
  }
}
provider "docker" {
  host    = "npipe:////.//pipe//docker_engine"
}

resource "docker_image" "syimage" {             # Docker Image İsmi : syimage
  name         = "enginyenice/sistem-yoneticiligi-odev:0.0.1" # Docker Image : https://hub.docker.com/repository/docker/enginyenice/sistem-yoneticiligi-odev
}

resource "docker_container" "sycontainer" {     # Docker Container İsmi: sycontainer
  image = docker_image.syimage.latest           # Belirtilen image 'ın son sürümünün indirilmesi
  name  = "sycontainer"                         # Docker Container İsmi: sycontainer
  ports {                                       # İç ve dış portlar
    internal = 80                               # İçeride dinlenecek port 80
    external = 8080                             # Dışarıya bağlanacak port 8080
                                                # Container 80 portu -> dışarıda ki 8080 portuna bağlandı.
  }
}