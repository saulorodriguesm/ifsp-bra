"""tbcar URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/3.1/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path, include
from django.conf.urls.static import static
from django.conf import settings
from tbcar.views import home, cadastro_cliente, listagem_clientes, cadastro_veiculo, listagem_veiculos, \
    Registrar, atualiza_cliente, exclui_cliente, listagem_parametro

urlpatterns = [
    path('admin/', admin.site.urls),
    path('accounts/', include('django.contrib.auth.urls')),
    path('registrar/', Registrar.as_view(), name='url_registrar'),
    path('', home, name='url_principal'),
    path('cadastro_cliente/', cadastro_cliente, name='url_cadastro_cliente'),
    path('listagem_clientes/', listagem_clientes, name='url_listagem_clientes'),
    path('cadastro_veiculo/', cadastro_veiculo, name='url_cadastro_veiculo'),
    path('listagem_veiculos/', listagem_veiculos, name='url_listagem_veiculo'),
    path('atualiza_cliente/<int:id>/', atualiza_cliente, name='url_atualiza_cliente'),
    path('exclui_cliente/<int:id>/', exclui_cliente, name='url_exlcui_cliente'),
    path('listagem_parametros/', listagem_parametro, name='url_listagem_parametro')

]

urlpatterns += static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)
